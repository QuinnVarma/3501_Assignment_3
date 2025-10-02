# 3501_Assignment_3

Students:
- Zachary Bowness (101188828)
- Kiera Pozzobon (101232098)
- Quinn Varma (101248900)

Game Objects:
- The yellow cube is the beacon that you want to go to next
- The white spheres are the beacons that have not been activated yet, you can not interact with them until they turn into yellow cubes
- The green spheres are the robots, hitting them or them hitting you will reduce your life by 1
- The pink spheres are the power ups, they increase your speed permanently when you touch them
- The red cubes are the asteroids, hitting them reduces your life total by 1

Game Rules:
- When you run out of lives, a red "Game Over" title will appear in the middle of the screen and all objects freeze
- When you touch all beacons, a green "You Win" title will appear in the middle of the screen and all objects freeze
- use the q,w,e,a,s,d keys to move around
- use the i,j,k,l to move the camera around
- use the "-" and "=" keys in order to grow and shrink the player

Game Systems: 
- There is an arrow on the screen that will point you to where the next yellow square beacon is (Not always accurate)
- When you grow, the size of your collision sphere gets bigger and you move faster
- When you shrink, the size of your collsion sphere gets smaller and you move slower
- The longer you press in the forward direction the faster you go
- press the "s" key in order to slow down
- You will always move in the forward direction
- Your life and remaining beacons can be seen in top left corner while playing
- Need to rerun the project in order to play the game again

Notes:
- No Bonus Marks were attempted
- The Collectibles.cc/h is empty but is used with inheritance with other classes

The structure of our src folder
src/
├─ main.cc
├─ ofApp.cc
└─ Game
    ├─ Context.cc/h
    └─ GameObjects
        ├─ GameObject.cc/h
        ├─ MyCustomCamera.cc/h
        └─ Collectables
            ├─ Collectables.cc/h
            ├─ Beacon.cc/h
            ├─ PowerUp.cc/h
        └─ Enemies
            ├─ Asteroid
            ├─ Robot