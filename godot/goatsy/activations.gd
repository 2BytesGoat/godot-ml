class_name GoateeActivations

var gt = Goatee.new()

func sigmoid(z: GoateeArray):
	# s = 1/(1+np.exp(-z))
	return gt._exp(z.scale(-1)).add(1).power(-1)
