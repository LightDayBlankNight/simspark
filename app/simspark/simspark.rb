#
# simspark.rb
#

# toggle log file recording
$recordLogfile = false

sparkSetupServer()
sparkSetupRendering()
sparkSetupInput()

# sparkAddFPSCamera($scenePath+'camera', 
#                   -10,-10,5,15,248,4,false,2,10,10)

# let spark create a default camera
sparkAddFPSCamera(
 		  $scenePath+'camera', 
 		  x = -5, 
 		  y = -40, 
 		  z = 2,
                  vAngle = 10.0,
                  hAngle = 10.0,
                  maxSpeed = 15.0,
 		  accel = 400.0,
 		  drag = 4,
 		  addCollider = false,
                  colliderRadius = 2.0
 		  )

# setup default input bindings
run "bindings.rb"

# create custom materials
material = new('kerosin/MaterialSolid', $serverPath+'material/matYellow');
material.setDiffuse(1.0,1.0,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matOrange');
material.setDiffuse(1.0,0.3,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matBlue');
material.setDiffuse(0.0,0.0,1.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matWhite');
material.setDiffuse(1.0,1.0,1.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRed');
material.setDiffuse(1.0,0.0,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRedGlow');
material.setDiffuse(1.0,0.0,0.0,1.0)
material.setEmission(0.5,0.0,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matGreen');
material.setDiffuse(0.1,0.6,0.1,1.0)
material.setAmbient(0.1,0.3,0.1,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matGrey');
material.setDiffuse(0.2,0.2,0.2,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matDarkGrey');
material.setDiffuse(0.05,0.05,0.05,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLightBlue');
material.setDiffuse(0.0,0.75,1.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matMagenta');
material.setDiffuse(1.0,0.0,0.75,1.0)

material = new('kerosin/Material2DTexture', $serverPath+'material/matBall');
material.setDiffuse(1.0,1.0,1.0,1.0)
material.setAmbient(0.5,0.5,0.5,1.0)
material.setDiffuseTexture('./soccerball.tga')

material = new('kerosin/Material2DTexture', $serverPath+'material/matGrass');
material.setDiffuse(1.0,1.0,1.0,1.0)
material.setAmbient(0.5,0.5,0.5,1.0)
material.setDiffuseTexture('./grass.tga')

#
# uncomment for logging setup (see spark.rb for reference)
#


#sparkLogAllToFile('spark.txt')
#sparkLogDebugToCerr()
sparkLogAllToCerr()

#
# uncomment any of the following to run a simulation
#

# create an arena with a bunch of boxes and spheres
# scene = get($scenePath)
# scene.importScene('rsg/boxspheres/simspark.rsg')

# create an arena to test various joint bodies
# scene = get($scenePath)
# scene.importScene('rsg/jointtest/simspark.rsg')

# source soccersim.rb to run the soccer simulation
run "soccersim.rb"




