#include "pch.h"
#include "Quest.h"

/// <summary>
/// 
/// </summary>
Quest::Quest()
{
	this->id = "0";
	this->title = "New Quest";
	this->npcId = "0";
	
	this->state = NOT_STARTED;
	this->objective = SLAY;
	this->quantity = 1;

	this->preQuestDialogue = "";
	this->inProgressDialogue = "";
	this->postQuestDialogue = "";

	this->money = 0;
	this->xp = 0;
}

void Quest::SetId(string id)
{
	this->id = id;
}

void Quest::SetTitle(string title)
{
	this->title = title;
}

void Quest::SetNpcId(string npcId)
{
	this->npcId = npcId;
}

void Quest::SetState(State state)
{
	this->state = state;
}

void Quest::SetObjective(Objective objective)
{
	this->objective = objective;
}

void Quest::SetQuantity(int amount)
{
	this->quantity = amount;
}

void Quest::SetPreQuestDialogue(string content)
{
	this->preQuestDialogue = content;
}

void Quest::SetInProgressDialogue(string content)
{
	this->inProgressDialogue = content;
}

void Quest::SetPostQuestDialogue(string content)
{
	this->postQuestDialogue = content;
}

void Quest::SetMoney(int amount)
{
	this->money = amount;
}

void Quest::SetXp(int amount)
{
	this->xp = xp;
}

string Quest::GetId()
{
	return this->id;
}

string Quest::GetTitle()
{
	return this->title;
}

string Quest::GetNpcId()
{
	return this->npcId;
}

State Quest::GetState()
{
	return this->state;
}

Objective Quest::GetObjective()
{
	return this->objective;
}

int Quest::GetQuantity()
{
	return this->quantity;
}

string Quest::GetPreQuestDialogue()
{
	return this->preQuestDialogue;
}

string Quest::GetInProgressDialogue()
{
	return this->inProgressDialogue;
}

string Quest::GetPostQuestDialogue()
{
	return this->postQuestDialogue;
}

int Quest::GetMoney()
{
	return this->money;
}

int Quest::GetXp()
{
	return this->xp;
}
