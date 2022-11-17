#include "gtest/gtest.h"
#include "pch.h"
#include "../File_System_Test_L0/MockResourceFileForHistory.h"
#include "../../File_System/Resource_File_ForHistory.h"

TEST(Resource_File_ForHistory, isOld_isOld_ReturnTrue) {
	Resource_File_ForHistory file(2022, 11, 4, "", "");

	bool oldness = file.isOld(2);

	EXPECT_TRUE(oldness);
}

TEST(Resource_File_ForHistory, isOld_isNotOld_ReturnFalse) {
	time_t t = time(0);
	struct tm * now = localtime(&t);
	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;
	Resource_File_ForHistory file(year, month, day, "", "");

	bool oldness = file.isOld(1);

	EXPECT_FALSE(oldness);
}

TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposing_NoExceptionThrown) {
	int moveSuccessfull = 0;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
}

TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposing_NoExceptionThrownBecauseMovingIsIdempotent) {
	int moveUnsuccessfull = 1;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
}
