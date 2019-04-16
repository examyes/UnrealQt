// Fill out your copyright notice in the Description page of Project Settings.

#include "QtUdpServer.h"

#include <string>


// Sets default values
AQtUdpServer::AQtUdpServer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UnrealQt::Init();

}

// Called when the game starts or when spawned
void AQtUdpServer::BeginPlay()
{
	Super::BeginPlay();

	UdpServer.setHostAddr("127.0.0.1");
	UdpServer.setPort(10086);
	UdpServer.start();
}

// Called every frame
void AQtUdpServer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UnrealQt::ProcessEvent();

	auto packets = UdpServer.readAllPackets();
	for (auto packet : packets)
	{
		std::string packetString = std::string(packet.begin(), packet.end());
		UE_LOG(LogTemp, Warning, TEXT("%s"), UTF8_TO_TCHAR(packetString.c_str()));
	}
}

void AQtUdpServer::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UdpServer.stop();
}

