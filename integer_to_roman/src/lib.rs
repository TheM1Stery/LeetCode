struct Solution;

fn roman_conversion(num: i32) -> char {
    match num {
        1 => 'I',
        5 => 'V',
        10 => 'X',
        50 => 'L',
        100 => 'C',
        500 => 'D',
        1000 => 'M',
        _ => '0',
    }
}

impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let mut result = String::new();
        let digits_count = num.ilog10() + 1;
        let mut ten = i32::pow(10, digits_count);

        while ten > 0 {
            let mut digit = num / ten % 10;
            if ten == 1000 {
                result.push_str(&"M".repeat(digit as usize));
                ten /= 10;
                continue;
            }

            let base = roman_conversion(ten);
            let half = roman_conversion(ten * 10 / 2);

            if digit == 9 {
                result.push(base);
                result.push(roman_conversion(ten * 10));
                digit -= 9;
            }
            if digit == 4 {
                result.push(base);
                result.push(half);
                digit -= 4;
            }
            if digit >= 5 {
                result.push(half);
                digit -= 5;
            }

            if digit < 4 {
                result.push_str(&base.to_string().repeat(digit as usize));
            }

            ten /= 10;
        }

        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_test() {
        assert_eq!(Solution::int_to_roman(3749), "MMMDCCXLIX");
    }

    #[test]
    fn second_test() {
        assert_eq!(Solution::int_to_roman(58), "LVIII");
    }

    #[test]
    fn third_test() {
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV");
    }
}
