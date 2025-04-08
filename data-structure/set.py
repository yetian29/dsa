

def main():
    """A set may contain multiple instances of the same element, set {1, 2, 2, 3} equal {1, 2, 3}"""
    setA = {1, 2, 2, 3}
    setB = {1, 2, 3}
    print(setA == setB)
    """Set elements are not ordered, should set {1, 2, 3} equal {3, 2, 1}"""
    setC = {3, 2, 1}
    print(setB == setC)


if __name__ == "__main__":
    main()
