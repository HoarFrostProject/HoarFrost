int fileSize(wchar_t* path) {
	HANDLE hFile = CreateFile(path,
		GENERIC_READ,          // open for reading
		0,                      // do not share
		NULL,                   // default security
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);
	DWORD dw = GetLastError();
	int size = GetFileSize(hFile, NULL);
	CloseHandle(hFile);
	return size;
}

int dirSize(wchar_t* path) {
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	HANDLE hFind = FindFirstFile(path, &ffd);
	int totalSize = 0;

	// List all the files in the directory with some info about them.

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			int size = (int)filesize.QuadPart;
			_tprintf(TEXT("  %s   %d\n"), ffd.cFileName, size);
			totalSize += size;
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	FindClose(hFind);

	return totalSize;
}