// Copyright Epic Games, Inc. All Rights Reserved.

#include "DeepGameGameModeBase.h"
#include "Developer/DesktopPlatform/Public/IDesktopPlatform.h"
#include "Developer/DesktopPlatform/Public/DesktopPlatformModule.h"
#include "Engine/Texture.h"

void ADeepGameGameModeBase::OpenFileDialog(const FString & DialogTitle, const FString & DefaultPath, const FString & FileTypes, TArray<FString> & OutFileNames)
{
	if (GEngine)
	{
		if (GEngine->GameViewport)
		{
			void* ParentWindowHandle = GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();
			IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
			if (DesktopPlatform)
			{
				uint32 SelectionFlag = 0; //A value of 0 represents single file selection while a value of 1 represents multiple file selection
				DesktopPlatform->OpenFileDialog(ParentWindowHandle, DialogTitle, DefaultPath, FString(""), FileTypes, SelectionFlag, OutFileNames);
			}
		}
	}
}

TArray<uint8> ADeepGameGameModeBase::ReadFileData(const FString& File)
{
	//Parse the data into a string array
	TArray<uint8> LoadedText;
	FFileHelper::LoadFileToArray(LoadedText, *File);
	return LoadedText;
}