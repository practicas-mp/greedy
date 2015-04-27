# -*- coding: utf-8 -*-


class Container(object):
    def __init__(self, weight, value):
        self.weight = weight
        self.value = value


def maximize_containers_value(containers, max_total_weight):
    m = {}

    for i in xrange(max_total_weight + 1):
        m[(0, i)] = 0

    for i in xrange(1, len(containers) + 1):
        for j in xrange(max_total_weight + 1):
            curr = containers[i - 1]
            if curr.weight <= j:
                m[(i, j)] = max(m[(i - 1, j)], m[(i - 1, j - curr.weight)] + curr.value)
            else:
                m[(i, j)] = m[(i - 1, j)]

    return m[(len(containers), max_total_weight)]