#pragma once

#include "pch.h"

using namespace std;

enum State
{
	NOT_STARTED,
	STARTED,
	ACHIEVED
};

enum Objectives {
	SLAY,
	LOOT,
	SAVE
};

class Quest
{
private:
	string id;
	string title;
	string npcId;

	State state;

	string preQuestDialogue;
	string inProgressDialogue;
	string postQuestDialogue;

	int money;
	int xp;

public:
	// Constructor
	Quest();

	// Setters
	void SetId(string id);
	void SetTitle(string title);
	void SetNpcId(string npcId);
	void SetState(State state);
	void SetPreQuestDialogue(string content);
	void SetInProgressDialogue(string content);
	void SetPostQuestDialogue(string content);
	void SetMoney(int amount);
	void SetXp(int amount);

	// Getters
	string GetId();
	string GetTitle();
	string GetNpcId();
	State GetState();
	string GetPreQuestDialogue();
	string GetInProgressDialogue();
	string GetPostQuestDialogue();
	int GetMoney();
	int GetXp();
};

