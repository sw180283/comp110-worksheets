#Worksheet 6

##Pseudocode
```
WHILE player is alive and game is running
	Change animation to stationary
	IF player is on ground	
		IF player press jump button
			WHILE player is not colliding with platform
				FOR movement in max jump height
					Change animation to jumping
					Move sprite up y-axis
				ENDFOR
				 Change animation to falling
				Move sprite down y-axis
			ENDWHILE
		ENDIF
	ENDIF
ENDWHILE
```

##State Diagram for UML
![alt text][state]

[state]: https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%206/State%20diagram%20for%20UML.png "State Diagram for UML"

##Class Diagram for UML
![alt text][class]

[class]: https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%206/Class%20diagram%20for%20UML.png "Class Diagram for UML"

##Flow Diagram for UML
![alt text][flow]

[flow]: https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%206/Flow%20chart%20for%20jumping.png "Flow Diagram for UML"

##Sequence Diagram for UML
![alt text][sequence]

[sequence]: https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%206/Sequence%20diagram%20for%20UML.png "Sequence Diagram for UML"

##Use Case Diagram UML
![alt text][use]

[use]: https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%206/Use%20case%20diagram%20chart.png "Use Case Diagram UML"
