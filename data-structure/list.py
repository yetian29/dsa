

def main():
    """List may contain multiple instances of the same element, so list listA different listB"""
    listA = [1, 2, 2, 3, 4, 5]
    listB = [1, 2, 3, 4, 5]
    print(listA == listB)
    """List elements are ordered, listA different listB"""
    listC = [5, 4, 3, 2, 1]
    print(listB == listC)


if __name__ == "__main__":
    main()
