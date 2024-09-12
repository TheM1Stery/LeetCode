struct Solution;

impl Solution {
    fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.len() == 1 {
            return strs[0].clone();
        }
        let mut common = String::new();
        let mut index = 0;
        let mut finish = false;

        while !finish {
            if strs[0].len() <= index {
                break;
            }
            let mut prev = if !strs[0].is_empty() {
                strs[0].as_bytes()[index] as char
            } else {
                Default::default()
            };
            for chr in &strs {
                let chr = chr.as_bytes();
                if index >= chr.len() {
                    finish = true;
                    break;
                }
                if prev != chr[index] as char {
                    finish = true;
                    break;
                }
                prev = chr[index] as char;
            }
            if !finish {
                common.push(prev);
            }
            index += 1
        }

        common
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn get_managed_vec(arr: &[&str]) -> Vec<String> {
        arr.iter().map(|x| x.to_string()).collect()
    }

    #[test]
    fn first_case() {
        let input = ["flower", "flow", "flight"];
        let expected = "fl".to_string();

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }

    #[test]
    fn second_case() {
        let input = ["dog", "racecar", "car"];
        let expected = String::new();

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }

    #[test]
    fn third_case() {
        let input = [""];
        let expected = String::new();

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }

    #[test]
    fn fourth_case() {
        let input = ["a"];
        let expected = "a";

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }

    #[test]
    fn fifth_case() {
        let input = ["ab", "a"];
        let expected = "a";

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }

    #[test]
    fn sixth_case() {
        let input = ["flower", "flower", "flower", "flower"];
        let expected = "flower";

        let actual = Solution::longest_common_prefix(get_managed_vec(&input));

        assert_eq!(expected, actual)
    }
}
