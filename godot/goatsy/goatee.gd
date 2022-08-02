class_name Goatee

""" TODOs
- [ ] test predefined length vs variable length
"""

func array(arr: Array):
	return GoateeArray.new(arr)

func _exp(arr: GoateeArray):
	for i in range(len(arr.values)):
		arr.values[i] = exp(arr.values[i])
	return arr
