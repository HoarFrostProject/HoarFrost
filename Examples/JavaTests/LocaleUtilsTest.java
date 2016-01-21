public class LocaleUtilsTest extends Assert {

  @DataProvider
  public Object[][] parseLocaleData() {
    return new Object[][]{
      {null, null},
      {"", LocaleUtils.ROOT_LOCALE},
      {"en", Locale.ENGLISH},
      {"en_US", Locale.US},
      {"en_GB", Locale.UK},
      {"ru", new Locale("ru")},
      {"ru_RU_some_variant", new Locale("ru", "RU", "some_variant")},
    };
  }

  @Test(dataProvider = "parseLocaleData")
  public void testParseLocale(String locale, Locale expected) {
    final Locale actual = LocaleUtils.parseLocale(locale);
    assertEquals(actual, expected);
  }
}