// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DeepGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEEPGAME_API ADeepGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FilePicker")
	static void OpenFileDialog(const FString& DialogTitle, const FString& DefaultPath, const FString& FileTypes, TArray<FString>& OutFileNames);

	/*Prints the data of the given file*/
	UFUNCTION(BlueprintCallable, Category = "FilePicker")
	static TArray<uint8> ReadFileData(const FString& File);
};
