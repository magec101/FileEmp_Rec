#include <cxxtest/TestSuite.h>

extern const char* fileEmp_RecMain(int argc, char** argv);

class FileEmp_RecTest : public CxxTest::TestSuite
{

public:
	void setUp() {
	}

	void tearDown(){
	}

	void test_SimpleIOCompare(){
		char* argv[] = {};
		const char* message = fileEmp_RecMain(sizeof(argv), argv);

		TS_ASSERT_EQUALS("Hello world\n", message);
	}
	
};