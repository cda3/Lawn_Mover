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

TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposingAFileNotPresentInHistoryFolder_NoExceptionThrownAndFileNotRenamed) {
	bool moveSuccessfull = true;
	bool fileNotInHistory = true;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileNotInHistory);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
	EXPECT_FALSE(file.isFileRenamed);
}

TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposingAFileNotPresentInHistoryFolder_NoExceptionThrownAndFileNotRenamed) {
	bool moveUnsuccessfull = false;
	bool fileNotInHistory = true;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull, fileNotInHistory);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
	EXPECT_FALSE(file.isFileRenamed);
}

TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposingAFileAlreadyPresentInHistoryFolder_NoExceptionThrownAndFileRenamed) {
	bool moveSuccessfull = true;
	bool fileInHistory = false;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileInHistory);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
	EXPECT_TRUE(file.isFileRenamed);
}

TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposingAFileAlreadyPresentInHistoryFolder_NoExceptionThrownAndFileRenamed) {
	bool moveUnsuccessfull = false;
	bool fileInHistory = false;
	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull, fileInHistory);

	file.dispose();

	EXPECT_TRUE(file.isDisposeCalled);
	EXPECT_TRUE(file.isFileRenamed);
}




//TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposing_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveSuccessfull = true;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}
//
//
//TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposing_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveUnsuccessfull = false;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}

//TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposingAFileNotPresentInHistoryFolder_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveSuccessfull = true;
//	bool fileNotInHistory = true;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileNotInHistory);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}
//
//TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposingAFileNotPresentInHistoryFolder_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveUnsuccessfull = false;
//	bool fileNotInHistory = true;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull, fileNotInHistory);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}
//
//TEST(Resource_File_ForHistory, dispose_NoErrorDuringDisposingAFileAlreadyPresentInHistoryFolder_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveSuccessfull = true;
//	bool fileInHistory = false;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileInHistory);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}
//
//TEST(Resource_File_ForHistory, dispose_ErrorDuringDisposingAFileAlreadyPresentInHistoryFolder_NoExceptionThrownBecauseMovingIsIdempotent) {
//	bool moveUnsuccessfull = false;
//	bool fileInHistory = false;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveUnsuccessfull, fileInHistory);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isDisposeCalled);
//}
//
//TEST(Resource_File_ForHistory, dispose_FileNotPresentInHistoryFolder_FileNotRenamed) {
//	bool moveSuccessfull = true;
//	bool fileNotInHistory = true;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileNotInHistory);
//
//	file.dispose();
//
//	EXPECT_FALSE(file.isFileRenamed);
//}
//
//TEST(Resource_File_ForHistory, dispose_FileAlreadyPresentInHistoryFolder_FileRenamed) {
//	bool moveSuccessfull = true;
//	bool fileInHistory = false;
//	MockResourceFileForHistory file(2022, 11, 4, "", "", moveSuccessfull, fileInHistory);
//
//	file.dispose();
//
//	EXPECT_TRUE(file.isFileRenamed);
//}

