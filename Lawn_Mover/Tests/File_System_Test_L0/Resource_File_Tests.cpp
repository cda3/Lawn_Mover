#include "pch.h"
#include "Resource_File_Tests.h"
#include "../File_System_Test_L0/MockResourceFile.h"
#include "../../File_System/Resource_File.h"


TEST(Resource_File, isOld_isOld_ReturnTrue) {
	Resource_File file(2022, 11, 4, "");

	bool oldness = file.isOld(2);
	   
	EXPECT_TRUE(oldness);
}

TEST(Resource_File, isOld_isNotOld_ReturnFalse) {
	time_t t = time(0);  
	struct tm * now = localtime(&t);
	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;
	Resource_File file(year, month, day, "");

	bool oldness = file.isOld(1);

	EXPECT_FALSE(oldness);
}

TEST(Resource_File, dispose_NoErrorDuringDisposing_NoExceptionThrown) {
	int deleteSuccessfull = 0;
	MockResourceFile file(2022, 11, 4, "", deleteSuccessfull);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
}

TEST(Resource_File, dispose_ErrorDuringDisposing_ThrowException) {
	int deleteUnsuccessfull = 1;
	MockResourceFile file(2022, 11, 4, "", deleteUnsuccessfull);

	ASSERT_THROW(file.dispose(), std::exception);
}
