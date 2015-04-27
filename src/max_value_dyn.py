# -*- coding: utf-8 -*-

from algorithms.max_value_dyn import Container, maximize_containers_value
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('filename')
parser.add_argument('max_total_weight', type=int)
args = parser.parse_args()

f = open(args.filename)

cs = [(int(x) for x in vals.split()) for vals in f.readlines()]
cs = [Container(*vals) for vals in cs]

print maximize_containers_value(cs, args.max_total_weight)
