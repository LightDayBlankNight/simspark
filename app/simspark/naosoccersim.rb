#
# prepare soccer simulation
#

# setup soccer specific materials
# run "scripts/rcs-materials.rb"
run "scripts/rcs-materials-textures.rb"

material = sparkCreate('kerosin/Material2DTexture', $serverPath+'material/matGrass');
material.setDiffuse(1.0,1.0,1.0,1.0)
material.setAmbient(0.5,0.5,0.5,1.0)
material.setDiffuseTexture('textures/rcs-naofield.png')

importBundle "soccer"

# soccer namespace
$soccerNameSpace = "Soccer"

# register a variable in the soccer namespace
def addSoccerVar(name, value)
   createVariable($soccerNameSpace, name, value)
end

# helper to get the value of a variable in the soccer namespace
def getSoccerVar(name)
  eval <<-EOS 
    #{$soccerNameSpace}.#{name} 
  EOS
end

# set a random seed (a seed of 0 means: use a random random seed)
randomServer = get($serverPath+'random')
if (randomServer != nil)
  randomServer.seed(0)
end

# the soccer field dimensions in meters
addSoccerVar('FieldLength', 6.0)
addSoccerVar('FieldWidth', 4.0)
addSoccerVar('FieldHeight', 40.0)
addSoccerVar('GoalWidth', 1.4)
addSoccerVar('GoalDepth', 0.4)
addSoccerVar('GoalHeight', 0.8)
addSoccerVar('PenaltyLength',0.6)
addSoccerVar('PenaltyWidth',2.0)
addSoccerVar('FreeKickDistance', 0.13)
addSoccerVar('AutomaticKickOff', false)
addSoccerVar('WaitBeforeKickOff', 2.0)

# agent parameters
addSoccerVar('AgentRadius',  0.6)

# ball parameters
addSoccerVar('BallRadius', 0.042)
addSoccerVar('BallMass',0.026)

# soccer rule parameters
addSoccerVar('RuleGoalPauseTime',3.0)
addSoccerVar('RuleKickInPauseTime',1.0)
addSoccerVar('RuleHalfTime',8.0 * 60)
addSoccerVar('RuleDropBallTime',30)
addSoccerVar('SingleHalfTime', true)
addSoccerVar('UseOffside',false)

# recorders
addSoccerVar('BallRecorder',"Ball/geometry/recorder")
addSoccerVar('LeftGoalRecorder',"leftgoal/GoalBox/BoxCollider/recorder")
addSoccerVar('RightGoalRecorder',"rightgoal/GoalBox/BoxCollider/recorder")

scene = get($scenePath)
if (scene != nil)
  scene.importScene('rsg/agent/nao/soccer.rsg')
end

# setup the GameControlServer
gameControlServer = get($serverPath+'gamecontrol')
if (gameControlServer != nil)
  gameControlServer.initControlAspect('GameStateAspect')
  gameControlServer.initControlAspect('BallStateAspect')
  gameControlServer.initControlAspect('SoccerRuleAspect')
end

# init monitorItems to transmit game state information
monitorServer = get($serverPath+'monitor')
if (monitorServer != nil)
  monitorServer.registerMonitorItem('GameStateItem')
end

# install the TrainerCommandParser to parse commands received from a
# monitor client
sparkRegisterMonitorCmdParser 'TrainerCommandParser'
