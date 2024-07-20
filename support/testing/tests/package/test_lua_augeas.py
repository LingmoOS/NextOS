from tests.package.test_lua import TestLuaBase


class TestLuaLuaAugeas(TestLuaBase):
    config = TestLuaBase.config + \
        """
        LINGMO_PACKAGE_LUA=y
        LINGMO_PACKAGE_AUGEAS=y
        LINGMO_PACKAGE_LUA_AUGEAS=y
        """

    def test_run(self):
        self.login()
        self.module_test("augeas")


class TestLuajitLuaAugeas(TestLuaBase):
    config = TestLuaBase.config + \
        """
        LINGMO_PACKAGE_LUAJIT=y
        LINGMO_PACKAGE_AUGEAS=y
        LINGMO_PACKAGE_LUA_AUGEAS=y
        """

    def test_run(self):
        self.login()
        self.module_test("augeas")
