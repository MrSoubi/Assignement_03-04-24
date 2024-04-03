//
// MainPage.xaml.cpp
// Implémentation de la classe MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace QuestTool;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

using namespace std;

unique_ptr<Quest> currentQuest;

MainPage::MainPage()
{
	currentQuest = make_unique<Quest>();

	InitializeComponent();
}


void QuestTool::MainPage::ID_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetId(Utils::PlatformToString(TB_ID->Text));
}


void QuestTool::MainPage::Title_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetTitle(Utils::PlatformToString(TB_Title->Text));
}


void QuestTool::MainPage::NPC_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetNpcId(Utils::PlatformToString(TB_NPC->Text));
}


void QuestTool::MainPage::PreQuestDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetPreQuestDialogue(Utils::PlatformToString(TB_PreQuestDialogue->Text));
}


void QuestTool::MainPage::InProgressDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetInProgressDialogue(Utils::PlatformToString(TB_InProgressDialogue->Text));
}


void QuestTool::MainPage::PostQuestDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetPostQuestDialogue(Utils::PlatformToString(TB_PostQuestDialogue->Text));
}


void QuestTool::MainPage::Money_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int localMoney;

	try
	{
		localMoney = stoi(Utils::PlatformToString(TB_Money->Text));
		currentQuest->SetMoney(localMoney);
	}
	catch (std::invalid_argument const& ex)
	{
		wstring temp = L"Incorrect format : " + Utils::PlatformToWString(TB_Money->Text);
		OutputDebugString(temp.c_str());

		currentQuest->SetMoney(0);
	}
}


void QuestTool::MainPage::XP_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int localXp;

	try
	{
		localXp = stoi(Utils::PlatformToString(TB_XP->Text));
		currentQuest->SetXp(localXp);
	}
	catch (std::invalid_argument const& ex)
	{
		wstring temp = L"Incorrect format : " + Utils::PlatformToWString(TB_XP->Text);
		OutputDebugString(temp.c_str());

		currentQuest->SetXp(0);
	}
}
