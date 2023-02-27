def gather_arguments(xs, hs):
    """
    verzamel informatie

    :param xs: op te delen lijst
    :param hs: slice-posities
    :return: xs opgedeeld a.d.h.v. hs
    """
    if len(hs) > 0:
        arguments = [[] for i in range(len(hs))]
        for i in range(len(hs) - 1):
            arguments[i].append(xs[hs[i]:hs[i + 1]])
        arguments[-1].append(xs[hs[-1]:])
    else:
        arguments = [[xs]]
    return arguments


def threading(arguments, unit):
    """
    Threading (voor nu nog een for-loop)

    :param arguments: argumenten die per thread worden meegegeven
    :return: samengevoegde lijst.
    """
    for i in range(len(arguments)):
        argument = arguments[i][0]
        operation(argument, unit)


def operation(xs_sub, unit):
    """
    Vervolg deel proces van merge sort

    :param xs_sub: deel van xs dat parelel gedraaid kan worden
    :param unit: grote van deel van xs
    :return: xs_sub gesorteerd
    """
    for h in range(0, len(xs_sub), unit * 2):
        l, r = h, min(len(xs_sub), h + 2 * unit)
        mid = h + unit
        p, q = l, mid
        while p < mid and q < r:
            if xs_sub[p] <= xs_sub[q]:
                p += 1
            else:
                tmp = xs_sub[q]
                xs_sub[p + 1: q + 1] = xs_sub[p:q]
                xs_sub[p] = tmp
                p, mid, q = p + 1, mid + 1, q + 1
    print(xs_sub)
    # TODO: samenvoegen van returnwaardes van operations


def merge_sort():
    xs = [8, 7, 6, 5, 4, 3, 2, 1]
    unit = 1
    hs = []
    for h in range(0, len(xs), unit * 2):
        hs.append(h)
    arguments = gather_arguments(xs, hs)
    threading(arguments, unit)


merge_sort()
