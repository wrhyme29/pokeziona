Kibbutz_PlayerHouse_MapScripts::
	.byte 0

Kibbutz_PlayerHouse_EventScript_PC::
	lockall
	call Kibbutz_PlayerHouse_EventScript_CheckPlayersPC
	end

Kibbutz_PlayerHouse_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	releaseall
	end

Kibbutz_PlayerHouse_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYERS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

Kibbutz_PlayerHouse_EventScript_Notebook::
	msgbox Kibbutz_PlayerHouse_Text_Notebook, MSGBOX_SIGN
	end

Kibbutz_PlayerHouse_EventScript_WallClock::
	goto_if_set FLAG_SET_WALL_CLOCK, Kibbutz_PlayerHouse_EventScript_CheckWallClock
	msgbox Kibbutz_PlayerHouse_Text_ClockIsStopped, MSGBOX_DEFAULT
	call Kibbutz_PlayerHouse_EventScript_SetWallClock
	setflag FLAG_SET_WALL_CLOCK
	playse SE_EXIT
	releaseall
	end

Kibbutz_PlayerHouse_EventScript_CheckWallClock::
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen FADE_TO_BLACK
	special Special_ViewWallClock
	releaseall
	end

Kibbutz_PlayerHouse_EventScript_SetWallClock::
	fadescreen FADE_TO_BLACK
	special StartWallClock
	return

Kibbutz_PlayerHouse_EventScript_EeveeBall::
	lock
	faceplayer
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Kibbutz_PlayerHouse_EventScript_GetEeveeParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Kibbutz_PlayerHouse_EventScript_GetEeveePC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Kibbutz_PlayerHouse_EventScript_GetEeveeCommonSetup::
	removeobject LOCALID_EEVEE_POKEBALL
	playfanfare MUS_OBTAIN_ITEM
	message Kibbutz_PlayerHouse_Text_ObtainedAnEevee
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	return

Kibbutz_PlayerHouse_EventScript_GetEeveeParty::
	call Kibbutz_PlayerHouse_EventScript_GetEeveeCommonSetup
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Kibbutz_PlayerHouse_EventScript_SetGotEevee
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Kibbutz_PlayerHouse_EventScript_SetGotEevee
	end

Kibbutz_PlayerHouse_EventScript_GetEeveePC::
	call Kibbutz_PlayerHouse_EventScript_GetEeveeCommonSetup
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Kibbutz_PlayerHouse_EventScript_TransferEeveeToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Kibbutz_PlayerHouse_EventScript_TransferEeveeToPC
	end

Kibbutz_PlayerHouse_EventScript_TransferEeveeToPC::
	call Common_EventScript_TransferredToPC
	goto Kibbutz_PlayerHouse_EventScript_SetGotEevee
	end

Kibbutz_PlayerHouse_EventScript_SetGotEevee::
	setflag FLAG_GOT_EEVEE
	setflag FLAG_SYS_POKEMON_GET
	release
	end

Kibbutz_PlayerHouse_Text_ClockIsStopped:
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

Kibbutz_PlayerHouse_Text_Notebook:
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Kibbutz_PlayerHouse_Text_ObtainedAnEevee::
    .string "{PLAYER} obtained an EEVEE!$"
