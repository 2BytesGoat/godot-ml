extends Node

""" ToDos
- [ ] add np.zeros()
- [ ] add transpose
- [ ] add np.dot()

"""

var gt = Goatee.new()
var activations = GoateeActivations.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	var arr = gt.array([0, 2])
	print(arr.shape)
	print(activations.sigmoid(arr).values)
