# RedBot-Project
The goal of this project was to, using the sparkfun redbot kit and a few extra sensors, create a robot that would go to the 
darkest part of the room and effectively hide from the user. The idea was that the robot would rotate 360 degrees while taking readings
from two light sensors mounted on its front right and front left bumper areas and then be able to go to the darkest area just from that
rotation. The implementation ended up being different because telling the bot how long to rotate and where to associate the darker areas
was more difficult than assumed. In this final implementation, the bot rotates one time to determine the length necessary to make one full
rotation, then divides that amount of time by 360 in order to set the delay between taking recordings when rotating. The next rotation
takes a measurement every degree by recording the light values from both sensors averaged into one array of size 360. Once all recordings
have been taken, the directions are averaged again based on the standard and intermediate cardinal directions. This leaves the bot with
only 8 possible directions in which it can go, however we found this technique to yield the best results in the field.
 
There were several problems with getting the Redbot to perform this task that didn't involve the actual collection of data. First of all,
the redbot had a sharp plastic piece attached to the bottom that was supposed to keep the back end off of the floor but this piece
really provided unnecessary friction on carpeted floors so we removed it and hot glued a little metal piece that did the same job with less
friction. Another difficult encountered was telling the bot when to stop. We eventually decided that, for the sake of this project, we
would make the bot a "hide-and-go-seek" robot so we gave it a timer that would force it to stop at a certain point and we also provided
a secondary way of stopping which involved the front bumpers. The original redbot came with two front bumpers that are designed to tell
the bot when it has hit something yet, having a multiple bots to work with meant that we had multiple bumpers and, thus, set up four
instead of two to cover the lower and upper front regions. The design includes code to tell the bot to check its surroundings again
when it runs into something and if the brightness of this new area is sufficiently low ,(2/3 of where it started, done by averaging all
360 points) then it will cease movement.

Other features were included with the bot as well. Namely, the bot will use both sensors to determine which direction is darker in front
of it and then turn as to even out the two sensor values. Finally, code was also included that tells the bot to start the whole process
when button 13 is pressed on the redbot so that the user can place it somewhere and then press the button when they are ready to play.
