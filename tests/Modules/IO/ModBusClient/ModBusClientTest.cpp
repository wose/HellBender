#include "gmock/gmock.h"
#include "IO/ModBusClient/ModBusClient.h"

using namespace ::testing;
using namespace hellbender::io;

class AModBusClient : public Test {
public:
    ModBusClient mbclient_;
};

TEST_F(AModBusClient, IsNotConnectedWhenCreated) {
    ASSERT_THAT(mbclient_.isConnected(), Eq(false));
}
