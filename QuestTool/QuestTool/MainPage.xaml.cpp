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
unique_ptr<Player> player;

MainPage::MainPage()
{
	currentQuest = make_unique<Quest>();
	player = make_unique<Player>();

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


void QuestTool::MainPage::Objective_OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	string selectedItem = Utils::PlatformToString(CB_Objective->SelectedValue->ToString());

	if (selectedItem == "Slay") {
		currentQuest->SetObjective(SLAY);
	}
	if (selectedItem == "Loot") {
		currentQuest->SetObjective(LOOT);
	}
	if (selectedItem == "Save") {
		currentQuest->SetObjective(SAVE);
	}
}


void QuestTool::MainPage::Quantity_OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	int localQuantity;

	try
	{
		localQuantity = stoi(Utils::PlatformToString(TB_Quantity->Text));
		currentQuest->SetQuantity(localQuantity);
	}
	catch (std::invalid_argument const& ex)
	{
		wstring temp = L"Incorrect format : " + Utils::PlatformToWString(TB_Quantity->Text);
		OutputDebugString(temp.c_str());

		currentQuest->SetQuantity(0);
	}
}


void QuestTool::MainPage::Talk_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (currentQuest->GetState() == NOT_STARTED)
	{
		TB_NPCDialogue->Text = TB_PreQuestDialogue->Text;
	}
	if (currentQuest->GetState() == IN_PROGRESS)
	{
		TB_NPCDialogue->Text = TB_InProgressDialogue->Text;
	}
	if (currentQuest->GetState() == ACHIEVED)
	{
		TB_NPCDialogue->Text = TB_PostQuestDialogue->Text;
	}
}


void QuestTool::MainPage::Start_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetState(IN_PROGRESS);
	TB_QuestState->Text = "In progress";
}


void QuestTool::MainPage::End_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetState(ACHIEVED);
	TB_QuestState->Text = "Achieved";
	player->AddMoney(currentQuest->GetMoney());
	player->AddXP(currentQuest->GetXp());

	TB_PlayerMoney->Text = player->GetMoney().ToString();
	TB_PlayerXP->Text = player->GetXP().ToString();
}


void QuestTool::MainPage::Reset_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	currentQuest->SetState(NOT_STARTED);
	TB_QuestState->Text = "Not started";
}
