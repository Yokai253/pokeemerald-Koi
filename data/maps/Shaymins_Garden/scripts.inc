# 1 "data/maps/Shaymins_Garden/scripts.pory"

# 2 "data/maps/Shaymins_Garden/scripts.pory"
    Shaymins_Garden_MapScripts::
# 3 "data/maps/Shaymins_Garden/scripts.pory"
	.byte 0

Shaymins_Garden_EventScript_Shaymin_Encounter::
# 7 "data/maps/Shaymins_Garden/scripts.pory"
	lockall
# 8 "data/maps/Shaymins_Garden/scripts.pory"
	setflag FLAG_SHAYMIN_ENCOUNTER
# 9 "data/maps/Shaymins_Garden/scripts.pory"
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
# 10 "data/maps/Shaymins_Garden/scripts.pory"
	delay 40
# 11 "data/maps/Shaymins_Garden/scripts.pory"
	waitmoncry
# 12 "data/maps/Shaymins_Garden/scripts.pory"
	setwildbattle SPECIES_SHAYMIN, 45
# 13 "data/maps/Shaymins_Garden/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 14 "data/maps/Shaymins_Garden/scripts.pory"
	dowildbattle
# 15 "data/maps/Shaymins_Garden/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 16 "data/maps/Shaymins_Garden/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Shaymins_Garden_EventScript_Shaymin_Encounter_2
# 19 "data/maps/Shaymins_Garden/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Shaymins_Garden_EventScript_Shaymin_Encounter_3
# 22 "data/maps/Shaymins_Garden/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Shaymins_Garden_EventScript_Shaymin_Encounter_4
# 25 "data/maps/Shaymins_Garden/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Shaymins_Garden_EventScript_Shaymin_Encounter_5
Shaymins_Garden_EventScript_Shaymin_Encounter_1:
# 28 "data/maps/Shaymins_Garden/scripts.pory"
	waitmessage
# 29 "data/maps/Shaymins_Garden/scripts.pory"
	releaseall
	return

Shaymins_Garden_EventScript_Shaymin_Encounter_2:
# 17 "data/maps/Shaymins_Garden/scripts.pory"
	call Shaymin_Caught
	goto Shaymins_Garden_EventScript_Shaymin_Encounter_1

Shaymins_Garden_EventScript_Shaymin_Encounter_3:
# 20 "data/maps/Shaymins_Garden/scripts.pory"
	call Shaymin_Won
	goto Shaymins_Garden_EventScript_Shaymin_Encounter_1

Shaymins_Garden_EventScript_Shaymin_Encounter_4:
# 23 "data/maps/Shaymins_Garden/scripts.pory"
	call Shaymin_RanAway
	goto Shaymins_Garden_EventScript_Shaymin_Encounter_1

Shaymins_Garden_EventScript_Shaymin_Encounter_5:
# 26 "data/maps/Shaymins_Garden/scripts.pory"
	call Shaymin_RanAway
	goto Shaymins_Garden_EventScript_Shaymin_Encounter_1


Shaymin_Won::
# 33 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_TO_BLACK
# 34 "data/maps/Shaymins_Garden/scripts.pory"
	removeobject 1
# 35 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


Shaymin_Caught::
# 40 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_TO_BLACK
# 41 "data/maps/Shaymins_Garden/scripts.pory"
	removeobject 1
# 42 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_FROM_BLACK
	return


Shaymin_RanAway::
# 47 "data/maps/Shaymins_Garden/scripts.pory"
	playmoncry SPECIES_SHAYMIN, CRY_MODE_ENCOUNTER
# 48 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_TO_BLACK
# 49 "data/maps/Shaymins_Garden/scripts.pory"
	removeobject 1
# 50 "data/maps/Shaymins_Garden/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 51 "data/maps/Shaymins_Garden/scripts.pory"
	msgbox Shaymin_RanAway_Text_0
	return


Shaymin_RanAway_Text_0:
# 51 "data/maps/Shaymins_Garden/scripts.pory"
	.string "Shaymin Fled.$"
