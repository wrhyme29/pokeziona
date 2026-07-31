TelAviv_Lab_MapScripts::
	.byte 0

TelAviv_Lab_ProfessorIlan_EventScript::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POKEMON_BOX_LINK_FROM_ILAN, TelAviv_Lab_ProfessorIlan_EventScript_GoExplore
	call TelAviv_Lab_ProfessorIlan_EventScript_ReceivePokemonBoxLink
	release
	end

TelAviv_Lab_ProfessorIlan_EventScript_ReceivePokemonBoxLink::
	msgbox TelAviv_Lab_ProfessorIlan_Text_HeardYouWereStarting, MSGBOX_DEFAULT
	giveitem ITEM_POKEMON_BOX_LINK
	setflag FLAG_RECEIVED_POKEMON_BOX_LINK_FROM_ILAN
	msgbox TelAviv_Lab_ProfessorIlan_Text_ExplainPokemonBoxLink, MSGBOX_DEFAULT
	return

TelAviv_Lab_ProfessorIlan_EventScript_GoExplore::
	msgbox TelAviv_Lab_ProfessorIlan_Text_GoExplore, MSGBOX_DEFAULT
	release
	end

TelAviv_Lab_ProfessorIlan_Text_HeardYouWereStarting:
	.string "PROF. ILAN: Oh, hi, {PLAYER}{KUN}!\p"
	.string "I heard you were ready to start your\n"
	.string "POKéMON journey here in Ziona!\p"
	.string "Ziona is really big, and you might not\n"
	.string "always be near a town or city.\p"
	.string "Here, {PLAYER}{KUN}, I ordered this for my\n"
	.string "field aide, but I think you should have\l"
	.string "this POKéMON BOX LINK.$"

TelAviv_Lab_ProfessorIlan_Text_ExplainPokemonBoxLink:
	.string "PROF. ILAN: The POKéMON BOX LINK\n"
	.string "is a high-tech tool that lets you\l"
	.string "access your POKéMON box from\l"
	.string "anywhere in Ziona!$"

TelAviv_Lab_ProfessorIlan_Text_GoExplore:
	.string "PROF. ILAN: Go explore Ziona! There\n"
	.string "are so many POKéMON to find!$"
	