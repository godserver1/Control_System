##################################################	WriteDigital	####################################################
							============

PROCESS:
=======

1)	Created Call Library function Node on LabVIEW VI, configured function Prototype.
2)	Created New empty project on Visual Studios 10.0 with initial settings as follows:
		a)	Select win32 application.
		b)	select dll as type in aditional settings.
3)	Go to Call Library function Node previously created and create a .c source file by Right-clicking on the pallete.
		i)	Make sure to set location of .c file in the the msvs project folder.
4)	open msvs project and write .c code.
5)	Go to project properties and include required .h,.lib,etc files location in corresponding VC++ directories. 