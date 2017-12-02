grades = [100, 100, 90, 40, 80, 100, 85, 70, 90, 65, 90, 85, 50.5]

def print_grades(grades_input):
    for grade in grades_input:
        print grade

def grades_sum(scores):
    scoreSum = 0
    for score in scores:
        scoreSum += score
    return scoreSum

def grades_average(grades_input):
    return grades_sum( grades_input ) / float( len( grades_input ) );

def grades_variance(scores):
    average = grades_average(scores)
    variance = 0
    for score in scores:
        variance += (average - score) ** 2
    return variance / len(scores)

def grades_std_deviation(variance):
    return variance ** 0.5





##### start of main



print_grades(grades)
print grades_sum(grades)
print grades_average(grades)
print grades_variance(grades)
print grades_std_deviation(grades_variance(grades))
