#include "pch.h"
#include "DisposeOldResources_Tests.h"
#include "../../Business_Logic/DisposeOldResources.h"
#include"MockResource.h"
#include "MockIResourcesReader.h"



TEST(DisposeOldResources, TwoResourcesFound_TwoResourcesOld_BothDeleted) {
	auto resources = std::vector<std::shared_ptr<IResource>>();
	std::shared_ptr<MockResource> firstResource(new MockResource(true));
	resources.push_back(firstResource);
	std::shared_ptr<MockResource> secondResource(new MockResource(true));
	resources.push_back(secondResource);

	auto reader = MockIResourcesReader(resources);
	auto deleter = DisposeOldResources(200, &reader);

	deleter.execute();

	EXPECT_TRUE(reader.isReadCalled);
	EXPECT_TRUE(firstResource->OldCalled);
	EXPECT_TRUE(firstResource->DisposedCalled);
	EXPECT_TRUE(secondResource->OldCalled);
	EXPECT_TRUE(secondResource->DisposedCalled);

}

TEST(DisposeOldResources, TwoResourcesFound_OneResourceOld_OneResourceDeleted) {
	auto resources = std::vector<std::shared_ptr<IResource>>();
	std::shared_ptr<MockResource> resource(new MockResource(false));
	resources.push_back(resource);
	std::shared_ptr<MockResource> oldResource(new MockResource(true));
	resources.push_back(oldResource);

	auto reader = MockIResourcesReader(resources);
	auto deleter = DisposeOldResources(200, &reader);

	deleter.execute();

	EXPECT_TRUE(reader.isReadCalled);
	EXPECT_TRUE(resource->OldCalled);
	EXPECT_FALSE(resource->DisposedCalled);
	EXPECT_TRUE(oldResource->OldCalled);
	EXPECT_TRUE(oldResource->DisposedCalled);

}



