#!/usr/bin/python3
def multiply_by_2(a_dictionary):
    if a_dictionary is not None:
        dic = {}
        tmp = {}
        for key, value in a_dictionary.items():
            newval = value * 2
            tmp = {key: newval}
            dic.update(tmp)
        return (dic)
    return None
