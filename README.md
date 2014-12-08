*Game*
====

Yay! This is our game!

**Recursive Link:**

https://github.com/Talador12/game

*Environment Setup*
---

**Installation Steps**

1. I included some of the installer files on our repo, just to ensure we all start with the same environment, under "Environment Setup"
2. Install visual studio, I installed to the 64 bit directory C:\Program Files\Microsoft Visual Studio 12.0
3. With visual studio installed, simply open the Visual Studio Solution file on the repo to start the project located at:

	Game\Project\Game\Game.sln

4. Then we setup the libraries! Allegro 5.0 first.
5. Copy bin, include, and lib folders from here to here 

	allegro-5.0.10-msvc-10.0\

	C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC
6. First you will have to right – click on the project1 and select properties or press Alt + Enter. If you choose the second option you have to click on the Solution Explorer at the right of the screen first. Then, after opening the properties of the project, select: Configuration Properties -> Linker -> Input Inside of input you will have to click on Additional Dependencies and scroll down to edit. There you will have to put something which is really important. Type in: allegro-5.0.10-monolith-mt-debug for debug then change the top dropdown from debug to release. Then do the same thing but instead use allegro-5.0.10-monolith-mt
7. Try to run. If you see msvcr100d.dll in an error, it's a mess involving C++ redistribute. I solved my issue by using the MT link instead of the MD link, but that should be set on 6 and I changed the project from MD to MT so that's on the repo.  This was a pain in the ass, but the code is so easy now.
8. Now onto Box 2D (TODO)


**Allegro 5.0**

http://cdn.allegro.cc/file/library/allegro/5.0.10/allegro-5.0.10-msvc-10.0.zip#sthash.08iMKpP0.dpuf

https://wiki.allegro.cc/index.php?title=Getting_Started (tutorials)

**Express 2013 for Windows Desktop**

http://www.visualstudio.com/en-US/products/visual-studio-express-vs

I recommend changing your theme to dark (not that this matters): http://msdn.microsoft.com/en-us/library/hh923906.aspx

**Box2D 2.3**

https://code.google.com/p/box2d/

http://box2d.org/about/ (for reference)

Box2D usage PDF tutorial on repo under Environment Setup

**Source Tree**

http://www.sourcetreeapp.com/

*Meeting Notes*
---

**11/30/2014**

Action RPG
Top down view (pokemon, zelda link to the past)
Seamless Transition
Cutscenes
Female Protagonist main character... who ends up realizing she is the antagonist in some way (writing TBD, we can work on it)
Physical Weapons (swords etc)
Magic
"Near Future" time, subtle magic infused (think korra episodes with spirits and trees everywhere)
We've discussed this being kind of a lost civilization that's the past, and the main character is somehow connected to all the shit that went down (maybe as the antagonist of the past? story TBD but we like this chain of thought)

We need to actually draft out a whole story sometime, since we want an immersive feel with the story, and between areas of the game (transition music challenge?)

**12/7/2014**

Game Time!

Setup the repo with environment steps.
Basic Project on repo!

Allegro made me sad for a bit.
EDIT: over an hour
EDIT EDIT: Many hours
EDIT EDIT EDIT: IT WORKS. IT'S SO PRETTY NOW.


Misc
---
**Michael's Music**

https://soundcloud.com/mmc-composition