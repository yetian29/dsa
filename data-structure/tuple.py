

def main():
    """Tuple can empty"""
    tupleA = ()
    print(tupleA)

    """Tuple may contain multiple instances of the same element"""
    tupleB = (1, -2, -2, 3, 4)
    tupleC = (1, -2, 3, 4)
    print(tupleB)
    print(tupleB == tupleC)
    """Tuple elements are ordered:"""
    tupleD = (4, 3, -2, 1)
    print(tupleC == tupleD)


if __name__ == "__main__":
	main()



