#include <iostream>
#include <memory>
#include <string>

#include <grpc/grpc.h>

#include "AggregateRepositoryImpl.h"
#include "ServerRunner.h"


using namespace std;
using namespace cms;

int main(int argc, char** argv) {

	const string address = "0.0.0.0:10001";

	grpc_init();

	cms::AggregateRepositoryImpl aggregate_repository_handler{};

	cms::ServerRunner server_runner {address, {&aggregate_repository_handler}};

	grpc_shutdown();

	return 0;
}