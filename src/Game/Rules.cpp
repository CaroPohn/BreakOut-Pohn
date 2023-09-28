#include "Rules.h"
#include "Screen.h"
#include "sl.h"

static int rulesTexture;
Rules rules;

void InitRules(Rules& rules)
{
	rulesTexture = slLoadTexture("assets/rules.png");

	rules.texture = rulesTexture;
	rules.x = GetScreenWidth() / 2;
	rules.y = GetScreenHeight() / 2;
	rules.width = GetScreenWidth();
	rules.height = GetScreenHeight();
}

void DrawRules(Rules& rules)
{
	slSprite(rules.texture, rules.x, rules.y, rules.width, rules.height);
}

void RulesInput(Scenes& scene)
{
	if (slGetKey(SL_KEY_ESCAPE))
	{
		slSoundStopAll();
		scene = Scenes::Menu;
	}
}

void RunRules(Scenes& scene, bool isNewScene)
{
	if (isNewScene)
	{
		InitRules(rules);
	}

	DrawRules(rules);
	RulesInput(scene);
}
