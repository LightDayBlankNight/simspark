# 
# materials.rb -- create custom materials for simspark
#

#----------------------------------------------------------------
# general colored materials
#----------------------------------------------------------------

# rainbow color
material = new('kerosin/MaterialSolid', $serverPath+'material/matYellow');
material.setDiffuse(1.0,1.0,0.0,1.0)
material.setAmbient(0.2,0.2,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matOrange');
material.setDiffuse(1.0,0.3,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRed');
material.setDiffuse(1.0,0.0,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRedGlow');
material.setDiffuse(1.0,0.0,0.0,1.0)
material.setEmission(0.5,0.0,0.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matMagenta');
material.setDiffuse(1.0,0.0,0.75,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matBlue');
material.setDiffuse(0.0,0.0,1.0,1.0)
material.setAmbient(0.0,0.0,0.2,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLightBlue');
material.setDiffuse(0.0,0.75,1.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matGreen');
material.setDiffuse(0.1,0.6,0.1,1.0)
material.setAmbient(0.1,0.3,0.1,1.0)

# shades of grey
material = new('kerosin/MaterialSolid', $serverPath+'material/matWhite');
material.setDiffuse(1.0,1.0,1.0,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matGrey');
material.setDiffuse(0.2,0.2,0.2,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matDarkGrey');
material.setDiffuse(0.05,0.05,0.05,1.0)


#----------------------------------------------------------------
# special purpose materials
#----------------------------------------------------------------


# ball
material = new('kerosin/MaterialSolid', $serverPath+'material/matBall');
material.setDiffuse(1.0,0.3,0.0,1.0)
material.setAmbient(0.2,0.06,0.0,1.0)

# running track around the field
material = new('kerosin/MaterialSolid', $serverPath+'material/matTrack');
material.setDiffuse(1.0,0.64,0.4,1.0)
material.setAmbient(0.2,0.01,0.0,1.0)

# grass
material = new('kerosin/MaterialSolid', $serverPath+'material/matGrass');
material.setDiffuse(0.1,0.6,0.1,1.0)
material.setAmbient(0.1,0.3,0.1,1.0)


#----------------------------------------------------------------
# left team
#----------------------------------------------------------------


# jersey color for left team
material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

# material with unums
material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft1');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft2');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft3');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft4');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft5');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft6');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft7');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft8');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft9');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft10');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matLeft11');
material.setDiffuse(0.0,0.75,1.0,1.0)
material.setAmbient(0.0,0.2,0.15,1.0)

#----------------------------------------------------------------
# right team
#----------------------------------------------------------------

# jersey color for right team
material = new('kerosin/MaterialSolid', $serverPath+'material/matRight');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

# material with unums
material = new('kerosin/MaterialSolid', $serverPath+'material/matRight1');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight2');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight3');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight4');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight5');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight6');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight7');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight8');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight9');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight10');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

material = new('kerosin/MaterialSolid', $serverPath+'material/matRight11');
material.setDiffuse(1.0,0.0,0.75,1.0)
material.setAmbient(0.2,0.0,0.15,1.0)

