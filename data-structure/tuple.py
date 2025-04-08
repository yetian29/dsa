

def main():
    """A tuple may contain multiple instance of the same element, so tuple (1, 2, 2, 3) different  (1, 2, 3)"""
    tupleA = (1, 2, 2, 3)
    tupleB = (1, 2, 3)
    print(tupleA == tupleB)
    """A tuple elements are ordered (1, 2, 3) different (3, 2, 1)"""
    tupleC = (3, 2, 1)
    print(tupleB == tupleC)


if __name__ == "__main__":
    main()
