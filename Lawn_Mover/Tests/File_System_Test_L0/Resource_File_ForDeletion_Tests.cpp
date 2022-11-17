#include "pch.h"
#include "Resource_File_ForDeletion_Tests.h"
#include "../File_System_Test_L0/MockResourceFileForDeletion.h"
#include "../../File_System/Resource_File_ForDeletion.h"


TEST(Resource_File_ForDeletion, isOld_isOld_ReturnTrue) {
	Resource_File_ForDeletion file(2022, 11, 4, "");

	bool oldness = file.isOld(2);
	   
	EXPECT_TRUE(oldness);
}

TEST(Resource_File_ForDeletion, isOld_isNotOld_ReturnFalse) {
	time_t t = time(0);  
	struct tm * now = localtime(&t);
	int year = now->tm_year + 1900;
	int month = now->tm_mon + 1;
	int day = now->tm_mday;
	Resource_File_ForDeletion file(year, month, day, "");

	bool oldness = file.isOld(1);

	EXPECT_FALSE(oldness);
}

TEST(Resource_File_ForDeletion, dispose_NoErrorDuringDisposing_NoExceptionThrown) {
	int deleteSuccessfull = 0;
	MockResourceFileForDeletion file(2022, 11, 4, "", deleteSuccessfull);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
}

TEST(Resource_File_ForDeletion, dispose_ErrorDuringDisposing_NoExceptionThrownBecauseDeletionIsIdempotent) {
	int deleteUnsuccessfull = 1;
	MockResourceFileForDeletion file(2022, 11, 4, "", deleteUnsuccessfull);

	file.dispose();
	
	EXPECT_TRUE(file.isDisposeCalled);
}
