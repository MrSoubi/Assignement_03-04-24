//
// MainPage.xaml.h
// Déclaration de la classe MainPage.
//

#pragma once

#include "MainPage.g.h"

namespace QuestTool
{
	/// <summary>
	/// Une page vide peut être utilisée seule ou constituer une page de destination au sein d'un frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();

	private:
		void ID_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Title_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NPC_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PreQuestDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void InProgressDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PostQuestDialogue_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Money_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void XP_OnFocusLost(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Objective_OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Quantity_OnLostFocus(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Talk_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Start_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void End_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Reset_OnClic(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
