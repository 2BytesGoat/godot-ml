extends 'res://addons/gut/test.gd'

func test_sigmoid():
	var gt = Goatee.new()
	var activations = GoateeActivations.new()
	
	var target_array = gt.array([0.5, 0.880797])
	var input_array = gt.array([0, 2])
	var output_array = activations.sigmoid(input_array)
	
	assert_eq(output_array.values, target_array.values, "Output should have been [0.5, 0.880797]")
