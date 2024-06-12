pub struct Solution;
fn replace_with_num(nums: &mut [i32], num: i32, range: (usize, usize)) {
    nums.iter_mut()
        .skip(range.0)
        .take(range.1)
        .for_each(|val| *val = num);
}

impl Solution {
    #[allow(clippy::ptr_arg)] // this is the signature given by LeetCode
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let count = nums.iter().fold((0, 0, 0), |mut acc, val| {
            match val {
                0 => acc.0 += 1,
                1 => acc.1 += 1,
                2 => acc.2 += 1,
                _ => (),
            };
            acc
        });
        let length = nums.len();
        replace_with_num(nums, 0, (0, count.0));
        replace_with_num(nums, 1, (length - count.1 - count.2, count.1));
        replace_with_num(nums, 2, (length - count.2, count.2));
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn first_test_case() {
        let input = vec![2, 0, 2, 1, 1, 0];
        let expected = vec![0, 0, 1, 1, 2, 2];
        let mut answer = input.clone();
        Solution::sort_colors(&mut answer);
        assert_eq!(answer, expected);
    }

    #[test]
    fn second_test_case() {
        let input = vec![2, 1];
        let expected = vec![1, 2];
        let mut answer = input.clone();
        Solution::sort_colors(&mut answer);
        assert_eq!(answer, expected);
    }
}
