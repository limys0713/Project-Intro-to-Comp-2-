Author: Lim Yik Seng (E24105038), Meng Ting Hsu (E24106830), Kor Yu Ee (E24105062), Zhang Wei Lun(E24106157)

Date: June, 11, 2022


Description
------------
Project 2: Uno

Target of this game: In order to win this game, the player need to clear his/her cards the fastest.

Digital Cards -> number (0-9)
>>0: 1 card per each color, 4 cards in total.
>>1-9: 2 cards per each color, 72 cards in total.

Function Cards -> The card that has its own functions.
➢Skip cards: The next person in line to play after this card is played loses his/her turn and is "skipped".
➢Reverse cards: This card reverses direction of play. Play to the left now passes to the right, and vice versa.
➢Draw 2 Cards: When you play this card, the next person to play must draw 2 cards.
➢Wild Cards: When you play this card, you may change the color being played to any color (including the current color) to continue play. 
➢Wild Draw 4 Cards: This card allows you to call the next color played and requires the next player to pick 4 cards.

Game rules:
• At first, send 7 cards to each person. Remaining cards are used as the deck.
• Turn over the first card of the deck (the number card shall prevail, if not, continue to turn over), the card faces up as the first card.
• The first player of that round is decided yourselves.
• Cards are played in a clockwise direction.
• Each player chooses to play one card of the same color, number or function as the card played by the previous player. (All function cards satisfy this rule)
• If left one card only, UNO is showed on the screen.
• The person who clears his cards fastest is the winner of the round.
• If there is no card to play before you win, players should draw one card for penalty.
**The remaining card amount will be shown(each of the player's remaining card amount)

Controls:
➢Left click the button of the mouse at the card to play the card.
➢Left click the button of the mouse at the card pile to draw the card.


-In this game, each players will get 7 cards at the beginning of the game and the players need to win the game by clearing all of his/her cards.


Platform information
---------------------
Cygwin Ver. 2.905, OS: Win10, 64-bit


Compilation Guide
------------------
1. Open terminal 1 and type enter "cd game" for entering the file.
2. Enter "qmake-qt5 -project". (Generate .pro file)
3. Enter "qmake-qt5 "QT+=widgets" "QT+=core gui" "QT+=widgets multimedia"". (Generate Makefile)
4. Enter "make".
5. Open terminal 2 and enter "startxwin".
6. execute /bin/pulseaudio.exe in Cygwin download folder by administrator.
7. Open terminal 1 and enter "export DISPLAY=:0.0".
8. Enter "./game" for execution.


Basic requirements:
------------------
Interface:
 Show Below items on your screen (Setting stage)
->Setting number of players ➢ Set as 3 -------------------------------------------------------------------------------------------------------------------------------- done
->Setting playing mode ➢ Players vs. Players -------------------------------------------------------------------------------------------------------------------------- done
->Players and their number of cards left. ------------------------------------------------------------------------------------------------------------------------------ done
->Card that played last round. ----------------------------------------------------------------------------------------------------------------------------------------- done
->Cards of yours. ------------------------------------------------------------------------------------------------------------------------------------------------------ done

UNO Cards:
->UNO cards have a total of 108 cards. --------------------------------------------------------------------------------------------------------------------------------- done
➢ 76 digital cards ---------------------------------------------------------------------------------------------------------------------------------------------------- done
➢ 32 function cards --------------------------------------------------------------------------------------------------------------------------------------------------- done
->Colors: Red, Yellow, Blue, Green. ------------------------------------------------------------------------------------------------------------------------------------ done
->Digital Cards:
➢ 0: 1 card per each color, 4 cards in total. ------------------------------------------------------------------------------------------------------------------------- done
➢ 1-9: 2 cards per each color, 72 cards in total. --------------------------------------------------------------------------------------------------------------------- done
->Function cards:
➢ Skip (Forbidden): 2 cards per each color, 8 cards in total. --------------------------------------------------------------------------------------------------------- done
➢ Reverse: 2 cards per each color, 8 cards in total. ------------------------------------------------------------------------------------------------------------------ done
➢ +2 Draw Two: 2 cards per each color, 8 cards in total. -------------------------------------------------------------------------------------------------------------- done
➢ Wild Card: Black, 4 cards in total.(Black color is the card can decide) --------------------------------------------------------------------------------------------- done
➢ +4 Wild Draw Four: Black, 4 cards in total.-------------------------------------------------------------------------------------------------------------------------- done

Function of cards:
->Skip card: The next person in line to play after this card is played loses his/her turn and is "skipped". ------------------------------------------------------------ done
->Reverse cards: This card reverses direction of play. Play to the left now passes to the right, and vice versa. ------------------------------------------------------- done
->Draw 2 Cards: When you play this card, the next person to play must draw 2 cards. ------------------------------------------------------------------------------------ done
->Wild Cards: When you play this card, you may change the color being played to any color (including the current color) to continue play. ------------------------------ done
->Wild Draw 4 Cards: This card allows you to call the next color played and requires the next player to pick 4 cards. -------------------------------------------------- done

Game Rules:
->At first, send 7 cards to each person. Remaining cards are used as the deck. ----------------------------------------------------------------------------------------- done
->Turn over the first card of the deck (the number card shall prevail, if not, continue to turn over), the card faces up as the first card.----------------------------- done
->The first player of that round is decided yourselves. ---------------------------------------------------------------------------------------------------------------- done
->Cards are played in a clockwise direction. --------------------------------------------------------------------------------------------------------------------------- done
->Each player chooses to play one card of the same color, number or function as the card played by the previous player. (All function cards satisfy this rule)---------- done
->If left one card only, you need to show UNO on the screen. ----------------------------------------------------------------------------------------------------------- done
->The person who clears his cards fastest is the winner of the round. -------------------------------------------------------------------------------------------------- done
->If there is no card to play before you win, players should draw one card for penalty. -------------------------------------------------------------------------------- done


Bonus
------
Play cards sound effect(When play a card, there will have the sound effect) ---------------------- done
Game win sound effect ---------------------------------------------------------------------------- done


Hope you enjoy the game, have a good day :)
