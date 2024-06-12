struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        fn roman_conversion(roman_numeral: char) -> i32 {
            match roman_numeral {
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => 0,
            }
        }
        s.chars()
            .fold((0, '0'), |(acc, before), val| match (val, before) {
                ('V', 'I') | ('X', 'I') => (acc + roman_conversion(val) - 2, val),
                ('L', 'X') | ('C', 'X') => (acc + roman_conversion(val) - 20, val),
                ('D', 'C') | ('M', 'C') => (acc + roman_conversion(val) - 200, val),
                _ => (acc + roman_conversion(val), val),
            })
            .0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_test() {
        assert_eq!(Solution::roman_to_int("III".to_string()), 3);
    }

    #[test]
    fn second_test() {
        assert_eq!(Solution::roman_to_int("LVIII".to_string()), 58);
    }

    #[test]
    fn third_test() {
        assert_eq!(Solution::roman_to_int("MCMXCIV".to_string()), 1994);
    }
}
