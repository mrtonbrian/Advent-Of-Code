# Solution
## Part 1
Part 1 is relatively straightforward; the main part is to get the input.

In my Python script they are the lines:
```python
passports = [p.replace(' ', '\n') for p in f.read().split('\n\n')]
passports = [dict(x.split(':') for x in p.split('\n')) for p in passports]
```
The first line simply breaks apart the file into an array of lines `p` that make up a specific passport then combines them into `1` line. The second line splits each passport into a dictionary of its components. Then, this dictionary is passed into the `Passport` object (overkill by the way) which then validates the passport using the if-statement:
```python
def isValid1(self):
        if len(self.values) == 8 or (len(self.values) == 7 and not 'cid' in self.values.keys()):
            return True
        return False
```

## Part 2
Since every passport that is valid by Part 2 rules is valid by Part 1 rules, we only check passports valid by Part 1 rules. To do this, the `Password` class has a `isValid2` function to check if the passport is valid by Part 2 rules.