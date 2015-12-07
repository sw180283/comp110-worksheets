#Worksheet 3

##Entity-relationship Diagram

![Entity Relationship Diagram](https://github.com/sw180283/comp110-worksheets/blob/master/Worksheet%203/entity_diagram.png)

##Pseudo code for server-client

```
Server

  Connect server to database
  Use database with top ten scores of each level

Client
  
  Request high score data for specific level from server
  IF player score is in top ten score:
    Push high score data to server
    Request updated high score data from server
  Display high score table in game
  
```
