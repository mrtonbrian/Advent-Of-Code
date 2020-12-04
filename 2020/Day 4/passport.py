import string

class Passport:
    values = {}

    def __init__(self, values):
        self.values = values

    def isValid1(self):
        if len(self.values) == 8 or (len(self.values) == 7 and not 'cid' in self.values.keys()):
            return True
        return False

    def isValid2(self):
        if int(self.values['byr']) < 1920 or int(self.values['byr']) > 2002:
            return False
        
        if int(self.values['iyr']) < 2010 or int(self.values['iyr']) > 2020:
            return False
        
        if int(self.values['eyr']) < 2020 or int(self.values['eyr']) > 2030:
            return False
        
        if 'in' in self.values['hgt']:
            if int(self.values['hgt'][:-2]) < 59 or int(self.values['hgt'][:-2]) > 76:
                return False
        elif 'cm' in self.values['hgt']:
            if int(self.values['hgt'][:-2]) < 150 or int(self.values['hgt'][:-2]) > 193:
                return False
        else:
            return False
        
        if len(self.values['hcl']) != 7 or self.values['hcl'][0] != '#' or not all(c in string.hexdigits for c in self.values['hcl'][1:]):
            return False
        
        if not self.values['ecl'] in ['amb', 'blu', 'brn', 'gry', 'grn', 'hzl', 'oth']:
            return False
        
        if not self.values['pid'].isdigit() or len(self.values['pid']) != 9:
            return False
        
        return True
    def __str__(self):
        return str(self.values)

with open("passport.in", "r") as f:
    passports = [p.replace(' ', '\n') for p in f.read().split('\n\n')]
    passports = [dict(x.split(':') for x in p.split('\n')) for p in passports]
    

    num_valid1 = 0
    num_valid2 = 0
    for passport in passports:
        p = Passport(passport)
        if p.isValid1():
            num_valid1 += 1
            if p.isValid2():
                num_valid2 += 1
    print("Part 1 Answer:", num_valid1)
    print("Part 2 Answer:", num_valid2)
