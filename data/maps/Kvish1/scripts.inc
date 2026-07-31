Kvish1_MapScripts::
	.byte 0

Kvish1_EventScript_AsfarOmar::
	trainerbattle_single TRAINER_ASFAR_OMAR, Kvish1_Text_AsfarOmarIntro, Kvish1_Text_AsfarOmarDefeat
	msgbox Kvish1_Text_AsfarOmarPostBattle, MSGBOX_AUTOCLOSE
	end

Kvish1_Text_AsfarOmarIntro:
	.string "Look at these cool BUG\n"
	.string "POKéMON I found!$"

Kvish1_Text_AsfarOmarDefeat:
	.string "Oh well - I'm going to\n"
	.string "show them to Ima!$"

Kvish1_Text_AsfarOmarPostBattle:
	.string "I've heard there are\n"
	.string "unique BUG POKéMON in\l"
	.string "in the the GOLAN FOREST.$"
