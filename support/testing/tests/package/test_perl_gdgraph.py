from tests.package.test_perl import TestPerlBase


class TestPerlGDGraph(TestPerlBase):
    """
    package:
        GDGraph
    direct dependencies:
        GD   XS
        GDTextUtil
    """

    config = TestPerlBase.config + \
        """
        LINGMO_PACKAGE_PERL=y
        LINGMO_PACKAGE_PERL_GDGRAPH=y
        """

    def test_run(self):
        self.login()
        self.module_test("GD")
        self.module_test("GD::Graph")
