//Copyright (c) 2016 Artem A. Mavrin and other contributors

#include "DialogueButton.h"
#include "DialogueSystemPrivatePCH.h"
#include "Components/Widget.h"
#include "Components/TextBlock.h"

#define LOCTEXT_NAMESPACE "DialogueSystem"

UDialogueButton::UDialogueButton()
{
	OnClicked.AddDynamic(this, &UDialogueButton::OnClick);
}

void UDialogueButton::OnClick()
{
	UWidget* WText = GetChildAt(0);
	UTextBlock* TextBlock = Cast<UTextBlock>(WText);
	if (TextBlock && WaitTask != nullptr)
	{
		FText SelectedQuestion = TextBlock->GetText();
		WaitTask->SetAnswer(SelectedQuestion);
	}
}

#if WITH_EDITOR
const FText UDialogueButton::GetPaletteCategory()
{
	return NSLOCTEXT("DialogueSystem", "Dialogue", "Dialogue");
}
#endif

/////////////////////////////////////////////////////

#undef LOCTEXT_NAMESPACE
