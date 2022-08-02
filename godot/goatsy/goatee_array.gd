class_name GoateeArray

var values: PoolRealArray
var shape: Array

func _init(arr: Array):
	values = __from_array(arr)
	shape = __extract_shape(arr)

func add(value: float):
	for i in range(len(self.values)):
		self.values[i] += value
	return self

func scale(value: float):
	for i in range(len(self.values)):
		self.values[i] *= value
	return self

func power(value: int):
	for i in range(len(self.values)):
		self.values[i] = pow(self.values[i], value)
	return self

func __from_array(arr: Array, values:= PoolRealArray([])):
	if not typeof(arr) == TYPE_ARRAY: 
		return values
	if not typeof(arr[0]) == TYPE_ARRAY:
		return PoolRealArray(arr)
	var l = len(arr[0])
	values.append_array(__from_array(arr[0]))
	for i in range(1, len(arr)):
		assert(len(arr[i]) == l, "ERROR: Dimmension missmach in arr")
		values.append_array(__from_array(arr[i]))
	return values

func __extract_shape(arr: Array, shape:=[]):
	if not typeof(arr) == TYPE_ARRAY: 
		return shape
	shape.append(len(arr))
	# check same length
	if typeof(arr[0]) == TYPE_ARRAY:
		var l = len(arr[0])
		for i in range(1, len(arr)):
			assert(len(arr[i]) == l, "ERROR: Dimmension missmach in arr")
		shape = __extract_shape(arr[0], shape)
	return shape
