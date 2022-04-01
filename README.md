# Little Tree for Sim Racing Rig

## CREDIT

Credit for this fantastic idea goes to [JamesF890](https://www.reddit.com/user/JamesF890/)
https://www.reddit.com/r/simracing/comments/tnk2wl/a_while_ago_i_saw_someone_on_here_post_a_picture/

## DESCRIPTION

This project brings side-to-side and forward-to-back motion to a little tree air freshener for use in Sim Racing.  This component can be attached to the top of a monitor and sways the air freshener based on telemetry provided from the racing sim.

## REQUIREMENTS

This project is designed for [rFactor 2](https://www.rfactor.net/) and [SIMHUB](https://www.simhubdash.com/) but I'm sure it can be adapted to other racing sims.

## SOFTWARE SETUP

In SIMHUB, the following code needs to be placed in the "Custom protocol" settings within the Arduino Settings page
![Custom Protocol Location](https://github.com/osajus/LittleTreeSim/blob/main/SIMHUB%20Custom%20Protocol.png)

```
format([GameRawData.CurrentPlayerTelemetry.mLocalAccel.x],'0.00') + ';' + 
format([GameRawData.CurrentPlayerTelemetry.mLocalAccel.y],'0.00') + ';' + 
format([GameRawData.CurrentPlayerTelemetry.mLocalAccel.z],'0.00')
```

The [SHCustomProtocol.h](https://github.com/osajus/LittleTreeSim/blob/main/SHCustomProtocol.h) file should be located in the SIMHUB Addons folder.  Mine is at: 
```
%PROGRAMFILES(X86)%\SimHub\_Addons\Arduino\DisplayClientV2
```
You can replace your existing file with the one attached or, if you already have custom code being used, just place the relevant code in the appropriate locations within the file. 

In this same folder, you will also need to modify the DisplayClientV2.ino file.  Around line 65, you will find the include section.  Add the following:
```
#include <Servo.h>
```

This sketch can be uploaded to your Arduino either through your IDE or by using SIMHUB.

### HARDWARE SETUP
Foward and Backward servo wires to I/O 10.
Left and Right servo wires to I/O pin 9.
These values can be changed in the [SHCustomProtocol.h](https://github.com/osajus/LittleTreeSim/blob/main/SHCustomProtocol.h) file, if you wish.  Lines 16/17.

I used 5V servos but you might want to check your particular hardware before applying the VCC and GND wires.

I drilled two holes (One in the Z ring and one in the X bar) and used bailing wire to connect each servo arm to the drilled holes.

### 3D MODELS
3mf files are included.  I won't provide the source file.  You'll need some m4 bolts and nuts to complete the build.  I used double sided sticky tape to attach the servos and some hot-snot to hold down the Arduino.  

### REVISIONS
I'm sure a lot of this could be done better.  Feel free to modify any of the source material to improve or meet your specific needs.
